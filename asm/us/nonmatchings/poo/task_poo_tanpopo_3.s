.syntax unified
	.align 2, 0
	.global task_poo_tanpopo_3
	.thumb
	.thumb_func
	.type task_poo_tanpopo_3, %function
task_poo_tanpopo_3: @ 080CF72C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CF74E
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x24]
	bl ReleaseObjTiles
	adds r0, r4, #0x0
	adds r0, #0x54
	bl func_08012304
_080CF74E:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
