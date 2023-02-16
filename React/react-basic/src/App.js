// jsx 的样式控制
// 1. 行内样式 - 在元素身上绑定style属性
// 2. 类名样式 - 在元素身上绑定一个className属性即可

import './app.css';

const style = {
  color:'red',
  fontSize:'50px'
}

// 动态控制active类名
const activeFlag = false

function App() {
  return (
    <div className="App">
      <span style={style}>this is span</span>
      <span className={activeFlag ? 'active' : 'notactive'}>测试</span>
    </div>
  );
}

export default App;

// 结尾笔记
// HTML标签记录
// 1. span标签：对行内区域进行划分
// 2. style属性: 可定义颜色，字体大小等
// 3. <></>：幽灵节点 (React独有)