/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/01/23 11:31:25 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

 int main()
 {
     void *mlx;//スクリーン接続識別子
     void *mlx_win;//ウィンドウ識別子
     int i;
     int j;
     int width = 1000; //ウィンドウのサイズ
     int height = 1000;

     mlx = mlx_init();//mlxの機能を使う前に一度呼び出す必要がある
     mlx_win = mlx_new_window(mlx, width, height,"test");
		// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
		//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
		//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
    	i= 0;
		while (i < width)
		{
				j = 0;
				while (j < height)
				{
						mlx_pixel_put(mlx, mlx_win, i, j, 127);
						j++;
				}
				i++;
		}
     mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
     //最初のうちはcntl+Cで強制終了すればおk
     //クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
     return (1);
 }
