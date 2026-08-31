.syntax unified
	.align 2, 0
	.global TaskDestroy
	.thumb
	.thumb_func
	.type TaskDestroy, %function
TaskDestroy:
	.incbin "roms/B8CJ.gba", 0xdbc, 0x2c
.syntax divided
