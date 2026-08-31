.syntax unified
	.align 2, 0
	.global task_btl_area_0
	.thumb
	.thumb_func
	.type task_btl_area_0, %function
task_btl_area_0: @ 0801D614
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r5, #0x00
	strb r5, [r4, #0x08]
	ldr r0, _0801D63C @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x00]
	ldr r0, _0801D640 @ =0x08B1EA00
	movs r1, #0xE0
	bl LoadObjTiles
	str r0, [r4, #0x04]
	strh r5, [r4, #0x0A]
	movs r0, #0x01
	strb r0, [r4, #0x09]
	pop {r4, r5}
	pop {r0}
	bx r0
_0801D63C: .4byte 0x08F69BA4
_0801D640: .4byte 0x08B1EA00
.syntax divided
