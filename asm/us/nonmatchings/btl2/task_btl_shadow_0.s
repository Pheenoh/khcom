.syntax unified
	.align 2, 0
	.global task_btl_shadow_0
	.thumb
	.thumb_func
	.type task_btl_shadow_0, %function
task_btl_shadow_0: @ 0802F4EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x08]
	ldr r5, [r1, #0x34]
	ldr r6, [r1, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x0C
	adds r0, r5, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0802F520
	ldr r0, _0802F518 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _0802F51C @ =0x08B22CBC
	b _0802F55A
	.byte 0x00, 0x00
_0802F518: .4byte 0x08B22CE4
_0802F51C: .4byte 0x08B22CBC
_0802F520:
	movs r0, #0x80
	lsls r0, r0, #0x0A
	adds r1, r5, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0802F54C
	ldr r0, _0802F544 @ =0x08B22EFE
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _0802F548 @ =0x08B22EE4
	b _0802F55A
	.byte 0x00, 0x00
_0802F544: .4byte 0x08B22EFE
_0802F548: .4byte 0x08B22EE4
_0802F54C:
	ldr r0, _0802F56C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _0802F570 @ =0x08B22BA8
_0802F55A:
	str r0, [r4, #0x0C]
	ldr r0, _0802F574 @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0802F56C: .4byte 0x08B22BBC
_0802F570: .4byte 0x08B22BA8
_0802F574: .4byte 0x08F69BA4
.syntax divided
