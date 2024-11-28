// function task() {
//   return new Promise((resolve, reject) => {
//     reject();
//   })
// }

// task().then(() => {
//   console.log('Success 1');
// }).then(() => {
//   console.log('Success 2');
// }).then(() => {
//   console.log('Success 3');
// }).catch(() => {
//   console.log('Error 1');
// }).then(() => {
//   console.log('Success 4');
// })

// var Person = function (firstName, lastName, dateOfBirth, measurements) {
//   this.firstName = firstName;
//   this.lastName = lastName;
//   this.dateOfBirth = dateOfBirth;
//   this.measurements = measurements;
// }

// person = new Person('John', 'Doe', new Date(2017, 4, 15), { weight: "58kg" });

// personClone = JSON.parse(JSON.stringify(person));

// print(person.firstName === personClone.firstName); // true

// print(person.measurements['weight'] === personClone.measurements['weight']); // true  

// print(person === personClone); // false

// print(person.dateOfBirth.toDateString() === personClone.dateOfBirth.toDateString()) // true

// function f(x) { x.value *= 5 }

// var b = { value: 2 };
// var c = b;

// f(b);

// console.log(b); // 1
// console.log(c); // 1

// function Student() {
//   this.studentId = "abc"
// }

// console.log(new Student().studentId)

// Student.prototype.classId = "xyz"

// console.log(new Student().classId)

A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

const a = A.slice(7).concat(A.slice(0, 7))

console.log(a)