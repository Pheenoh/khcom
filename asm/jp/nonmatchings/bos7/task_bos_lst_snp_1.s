.syntax unified
	.align 2, 0
	.global task_bos_lst_snp_1
	.thumb
	.thumb_func
	.type task_bos_lst_snp_1, %function
task_bos_lst_snp_1:
	.incbin "roms/B8CJ.gba", 0x112540, 0x50
.syntax divided
