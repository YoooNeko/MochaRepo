package main

import (
	"runtime"

	"github.com/gin-gonic/gin"
)

func main() {

	r := gin.Default()

	// 提供静态文件服务
	r.Static("/static", "../react-basic/build/static")
	r.StaticFile("/", "../react-basic/build/index.html")

	// 启动 HTTP 服务器
	if runtime.GOOS == "windows" {
		r.Run(":8888")
	} else {
		r.Run(":8080")
	}
}
