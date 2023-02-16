// React: 框架核心
import React from 'react';

// ReactDOM: 专门做渲染相关的包
import ReactDOM from 'react-dom/client';

//应用的全局样式文件
import './index.css';

// 引入根组件
import App from './App';

const root = ReactDOM.createRoot(document.getElementById('root'));

// 渲染根组件APP 到一个id为root的dom节点上
root.render(
  // 严格模式节点需要去掉
  // useEffect的执行时期
  //<React.StrictMode>
  <App />
  //</React.StrictMode>
);