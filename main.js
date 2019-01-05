const {AdBlockClient, FilterOptions} = require('ad-block');
var downloadFileSync = require('download-file-sync');
const fs = require('fs');
// var content = downloadFileSync('https://easylist.to/easylist/easylist.txt');
const client = new AdBlockClient();
let client2 = new AdBlockClient();
// client.parse(content);
client2.deserialize(fs.readFileSync('an.dat'));
// fs.writeFileSync('an.dat', client.serialize(), 'binary');
var b1 = client2.matches('https://amd-ssl.cdn.turner.com/cnn/big/ads/2018/07/13/KoreanAirGlobal_30s_EN_v2_576x324.mp4', FilterOptions.noFilterOption, 'slashdot.org')
var b2 = client2.matches('https://github.com/brave/ad-block.mp4', FilterOptions.noFilterOption, 'slashdot.org')

console.log('match: ', b1)
console.log('match: ', b2)
