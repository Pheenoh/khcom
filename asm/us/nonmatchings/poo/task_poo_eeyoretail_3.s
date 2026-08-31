.syntax unified
	.align 2, 0
	.global task_poo_eeyoretail_3
	.thumb
	.thumb_func
	.type task_poo_eeyoretail_3, %function
task_poo_eeyoretail_3: @ 080CFA4C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CFA62
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
_080CFA62:
	adds r0, r4, #0x0
	adds r0, #0x24
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
