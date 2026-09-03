.syntax unified
	.text
	.align 2, 0
	.global task_fld_sora_1
	.thumb
	.thumb_func
	.type task_fld_sora_1, %function
task_fld_sora_1:
	.incbin "roms/B8CP.gba", 0x37fc0, 0x620
.syntax divided
