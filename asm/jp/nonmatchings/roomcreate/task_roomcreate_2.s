.syntax unified
	.align 2, 0
	.global task_roomcreate_2
	.thumb
	.thumb_func
	.type task_roomcreate_2, %function
task_roomcreate_2:
	.incbin "roms/B8CJ.gba", 0x3f6d4, 0xc
.syntax divided
