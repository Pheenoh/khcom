.syntax unified
	.align 2, 0
	.global task_roomcreate_1
	.thumb
	.thumb_func
	.type task_roomcreate_1, %function
task_roomcreate_1:
	.incbin "roms/B8CJ.gba", 0x3f308, 0x3cc
.syntax divided
