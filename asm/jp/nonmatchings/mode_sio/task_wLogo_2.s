.syntax unified
	.text
	.align 2, 0
	.global task_wLogo_2
	.thumb
	.thumb_func
	.type task_wLogo_2, %function
task_wLogo_2:
	.incbin "roms/B8CJ.gba", 0xb48ac, 0x4
.syntax divided
