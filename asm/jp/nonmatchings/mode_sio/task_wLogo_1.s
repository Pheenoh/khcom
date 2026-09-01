.syntax unified
	.align 2, 0
	.global task_wLogo_1
	.thumb
	.thumb_func
	.type task_wLogo_1, %function
task_wLogo_1:
	.incbin "roms/B8CJ.gba", 0xb483c, 0x70
.syntax divided
