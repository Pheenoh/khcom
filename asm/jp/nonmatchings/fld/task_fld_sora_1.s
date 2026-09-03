.syntax unified
	.text
	.align 2, 0
	.global task_fld_sora_1
	.thumb
	.thumb_func
	.type task_fld_sora_1, %function
task_fld_sora_1:
	.incbin "roms/B8CJ.gba", 0x33bc8, 0x620
.syntax divided
