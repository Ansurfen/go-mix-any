package main

import "syscall"

func main() {
	callpy()
}

func callpy() {
	syscall.NewLazyDLL("callc.dll").NewProc("callpy").Call()
}
