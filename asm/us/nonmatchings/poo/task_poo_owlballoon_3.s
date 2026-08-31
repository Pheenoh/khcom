.syntax unified
	.align 2, 0
	.global task_poo_owlballoon_3
	.thumb
	.thumb_func
	.type task_poo_owlballoon_3, %function
task_poo_owlballoon_3: @ 080CCB4C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CCB6A
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08012304
_080CCB6A:
	adds r0, r4, #0x0
	adds r0, #0xB0
	bl TaskPoolDestroy
	adds r0, r4, #0x0
	adds r0, #0x90
	bl func_080CCBD4
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
