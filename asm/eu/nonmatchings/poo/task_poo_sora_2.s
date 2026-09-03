.syntax unified
	.text
	.align 2, 0
	.global task_poo_sora_2
	.thumb
	.thumb_func
	.type task_poo_sora_2, %function
task_poo_sora_2:
	.incbin "roms/B8CP.gba", 0xc80e0, 0x118
.syntax divided
