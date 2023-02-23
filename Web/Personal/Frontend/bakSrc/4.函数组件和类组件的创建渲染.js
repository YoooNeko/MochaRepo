import './app.css';
import React from "react"

// 函数组件的创建和渲染
// 创建 (组件首字母大写)
// 函数组件必须有返回值
// 渲染 <Hello/>    <Hello></Hello>
function Hello() {
  const clickHandler = () => {
    console.log('函数组件的事件被触发了');
  }
  return <div onClick={clickHandler}>hello</div>
}

// 类组件的创建和渲染
class WorldComponent extends React.Component {
  clickHandler = () => {
    console.log('类组件的事件被触发了')
  }
  render() {
    return <div onClick={this.clickHandler}>this is class Component</div>
  }
}

function App() {
  return (
    <div className="App">
      <Hello/>
      <Hello></Hello>
      <WorldComponent/>
      <WorldComponent></WorldComponent>
    </div>
  );
}

export default App;

// 结尾笔记
// 组件能够使用类似标签的方式被渲染。
// 类组件需要继承React.Component并且调用render方法