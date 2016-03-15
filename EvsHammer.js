var addon = require('./build/Release/EvsHammer.node');

console.log(addon.Add(3, 8));
console.log(addon.GetClipDatabase(5).msg);