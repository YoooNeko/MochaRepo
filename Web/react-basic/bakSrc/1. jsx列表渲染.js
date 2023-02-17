// 1.识别常规变量
// 2.原生js方法调用
// 3.三目运算符
// const name = 'RoyalDoll'
// const getAge = () => {
//   return 18
// }
// const flag = true

// 4.列表渲染
//    map重复渲染的是哪个模板，就return谁
//    注意事项：便利列表时需要一个类型为不可重复的key
const songs = [
  { id: 1, writer:'周杰伦', name:'菊花台'},
  { id: 2, writer:'周杰伦', name:'告白气球'},
  { id: 3, writer:'周杰伦', name:'白色风车'}
]

function App() {
  return (
    <div className="App">
      {/* { name }
      { getAge() }
      { flag ? '真棒' : '真菜' } */}
      <ul>
        { songs.map(songs => <li key={songs.id}>{songs.id}. {songs.writer}: {songs.name}</li>) }
      </ul>
    </div>
  );
}

export default App;

// 结尾笔记
// HTML标签记录
// 1. ul标签：Unordered List无序标签
// 2. li标签：Lists定义列表项
// 3. ol标签：Ordered List有序标签
// 4. div标签：Division表示分割区域