.syntax unified
	.align 2, 0
	.global AllocObjAffine
	.thumb
	.thumb_func
	.type AllocObjAffine, %function
AllocObjAffine:
	.incbin "roms/B8CJ.gba", 0x2cb4, 0x258
.syntax divided
