package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Print("输入一个数判断(0~100): ")
	var a = 0
	var i = 5
	var num = rand.Intn(100) + 1
	for i > 0 {
		fmt.Scanf("%d", a)
		if a == num {
			fmt.Printf("在还有%v次机会时,你成功了，数字是20 \n", i)
		} else if a < num {
			if num-a <= 10 {
				fmt.Printf("有点小哦,还有%v次机会 \n", i)
				i--
			} else if num-a > 10 {
				fmt.Printf("小了,你还有%v次机会 \n", i)
				i--
			}
		} else if a > num {
			if a-num <= 10 {
				fmt.Printf("有点大哦,还有%v次机会 \n", i)
				i--
			} else if a-num < 10 {
				fmt.Printf("大了,你还有%v次机会 \n", i)
				i--
			}
		} else if a == 2333 {
			fmt.Print("作弊码!\n")
			fmt.Println("输入1. +5次机会")
			fmt.Println("输入2. 看答案")
			var zbm = 0
			fmt.Scanf("%d", zbm)
			if zbm == 1 {
				fmt.Println("+5次机会")
				i += 5
			} else if zbm == 2 {
				fmt.Printf("%v\n", num)
			}
		} else {
			fmt.Println("输入错误，次数-1")
			i--
		}
	}
}
