import './app.css';
import React from "react"

// 函数组件的创建和渲染
// 创建 (组件首字母大写)
// 函数组件必须有返回值
// 渲染 <Hello/>    <Hello></Hello>
function Hello() {
  const clickHandler = (e, msg) => {
    console.log('函数组件的事件被触发了', e, msg);
  }
  return <div onClick={(e)=>clickHandler('abcdefg')}>打开百度</div>
}

// 类组件的创建和渲染
class WorldComponent extends React.Component {
  clickHandler = (e) => {
    e.preventDefault()
    console.log('类组件的事件被触发了', e)
  }
  render() {
    return <div><a onClick={this.clickHandler} href="https://baidu.com">打开百度</a></div>
  }
}

function App() {
  return (
    <div className="App">
      <Hello/>
      <WorldComponent/>
    </div>
  );
}

export default App;

// 结尾笔记
// HTML标签记录
// 1. a标签：超链接