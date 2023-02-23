// React: 框架核心
import React from 'react';

// ReactDOM: 专门做渲染相关的包
import ReactDOM from 'react-dom/client';

//应用的全局样式文件
import './index.css';

// 引入根组件
import App from './App';

// 渲染根组件APP 到一个id为root的dom节点上
ReactDOM.createRoot(document.getElementById('root')).render(<App />);
