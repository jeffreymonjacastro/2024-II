import librosa
import numpy as np
import pandas as pd
import os
from sklearn.preprocessing import MinMaxScaler

# Specify the folder name containing the audio files
path = '/home/jamcy/Github/2024-II/ML/W7/cleaned_data/'

# Other ways to extract features
# def feature_extraction(file_path):
#     audio, sample_rate = librosa.load(file_path, res_type='kaiser_fast')
#     mfcc = np.mean(librosa.feature.mfcc(y=audio, sr=sample_rate, n_mfcc=40).T, axis=0)
#     chroma = np.mean(librosa.feature.chroma_stft(y=audio, sr=sample_rate).T, axis=0)
#     spectral_contrast = np.mean(librosa.feature.spectral_contrast(y=audio, sr=sample_rate).T, axis=0)
#     features = np.hstack([mfcc, chroma, spectral_contrast])
#     return features


def feature_extraction(file_path):
    # Load the audio file
    audio, sample_rate = librosa.load(file_path, res_type='kaiser_fast')

    # Extract features from the audio
    mfcc = np.mean(librosa.feature.mfcc(y=audio, sr=sample_rate, n_mfcc=40).T, axis=0)
    return mfcc

def save_features(path):
    # List to store features
    features_list_positive = []  
    features_list_negative = [] 

    path_positive = path + '/Positive/'
    for audio in os.listdir(path_positive):
        feature = feature_extraction(os.path.join(path_positive, audio)) 
        features_list_positive.append(feature)

    path_negative = path + '/Negative/'
    for audio in os.listdir(path_negative):
        feature = feature_extraction(os.path.join(path_negative, audio)) 
        features_list_negative.append(feature) 

    # Convert the list to a DataFrame. Each row is a feature vector
    df_positive = pd.DataFrame(features_list_positive) 
    df_negative = pd.DataFrame(features_list_negative) 

    # Rename the columns
    df_positive.columns = [f'f{i}' for i in range(1, 41)]
    df_negative.columns = [f'f{i}' for i in range(1, 41)]

    # Add a column to specify if the audio is positive or negative covid case
    df_positive['covid'] = 1
    df_negative['covid'] = 0

    # Combine both DataFrames
    df_combined = pd.concat([df_positive, df_negative])

    # Normalize feature vectors using MinMaxScale (excluding 'covid' column)
    scaler = MinMaxScaler()
    df_combined.iloc[:, :-1] = scaler.fit_transform(df_combined.iloc[:, :-1]) 

    # Shuffle the rows of the combined DataFrame randomly
    df_combined = df_combined.sample(frac=1, random_state=42).reset_index(drop=True)

    # Save the combined and normalized DataFrame to a CSV file
    df_combined.to_csv('audio_features.csv', index=False)

save_features(path)