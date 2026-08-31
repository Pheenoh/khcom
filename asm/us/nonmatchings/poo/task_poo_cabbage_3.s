.syntax unified
	.align 2, 0
	.global task_poo_cabbage_3
	.thumb
	.thumb_func
	.type task_poo_cabbage_3, %function
task_poo_cabbage_3: @ 080D15F0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080D1606
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
_080D1606:
	adds r0, r4, #0x0
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D1618
	adds r0, r4, #0x0
	adds r0, #0x44
	bl func_08012304
_080D1618:
	adds r0, r4, #0x0
	adds r0, #0xA8
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
