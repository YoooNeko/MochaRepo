// 条件渲染
// 技术方案：三元表达式, 逻辑&&运算

// 1. 三元表达式 - 满足条件渲染一个span标签
const flag = false // true

function App() {
  return (
    <div className="App">
      {
        flag ? <div><span>this is span</span><span>  abc  </span></div> : null
      }

      {
        true && <span>this is span</span>
      }
    </div>
  );
}

export default App;

// 结尾笔记
// HTML标签记录
// 1. span标签：对行内区域进行划分
// 2. h1-h6标签：标题 h1是最大的标题，h6是最小的标题