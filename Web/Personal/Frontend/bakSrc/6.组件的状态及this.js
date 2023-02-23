import './app.css';
import React from "react"

// 类组件
class NameCounter extends React.Component {
  state = {
    name:'Li hua',
    LiCounter:1,
    HanCounter:0,
  }

  Test() {
    console.log(this)
  }

  changeName = () => {    // 这里类的成员函数必须用箭头函数才能自动绑定this指针（或者在构造函数中调用bind()并且必须在super之后）
    console.log(this)
    this.setState(prevState => {
      if(prevState.name === 'Li hua') {
        return {name:'Han Meimei', HanCounter:prevState.HanCounter + 1}
      }
      else {
        return {name:'Li hua', LiCounter:prevState.LiCounter + 1}
      }
    })
  }
  

  render() {
    return <div>
      这是一个类组件
      当前的名字是: {this.state.name}，当前名字的计数是: {this.state.name === 'Li hua' ? this.state.LiCounter : this.state.HanCounter}
      <button onClick={this.changeName}>修改名字</button>
      <button onClick={() => this.Test()}>打印this</button>
    </div>
  }
}

// 根组件
function App() {
  return (
    <div className="App">
      <NameCounter/>
    </div>
  );
}

export default App;

// 结尾笔记