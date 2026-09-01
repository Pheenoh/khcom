.syntax unified
	.align 2, 0
	.global TaskPoolInit
	.thumb
	.thumb_func
	.type TaskPoolInit, %function
TaskPoolInit:
	.incbin "roms/B8CJ.gba", 0xe64, 0x40
.syntax divided
