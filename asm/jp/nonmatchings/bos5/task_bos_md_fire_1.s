.syntax unified
	.align 2, 0
	.global task_bos_md_fire_1
	.thumb
	.thumb_func
	.type task_bos_md_fire_1, %function
task_bos_md_fire_1:
	.incbin "roms/B8CJ.gba", 0xfd2e8, 0x4c
.syntax divided
