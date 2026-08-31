.syntax unified
	.align 2, 0
	.global func_08028468
	.thumb
	.thumb_func
	.type func_08028468, %function
func_08028468: @ 08028468
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	ldr r6, _080284B4 @ =0x02039B84
	ldr r0, [r6, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _080284AC
	movs r1, #0xD6
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r1, _080284B8 @ =0x09618118
	str r1, [r0, #0x00]
	ldr r0, [r3, #0x08]
	ldrh r0, [r0, #0x06]
	bl LoadObjPaletteBank
	ldr r6, [r6, #0x00]
	ldr r2, [r6, #0x68]
	ldr r3, [r6, #0x6C]
	ldr r0, _080284BC @ =0xFFFF7FFF
	ands r3, r0
	ldr r4, _080284C0 @ =0x00000000
	ldr r5, _080284C4 @ =0x00800000
	adds r0, r2, #0x0
	adds r1, r3, #0x0
	orrs r1, r5
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
_080284AC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080284B4: .4byte 0x02039B84
_080284B8: .4byte 0x09618118
_080284BC: .4byte 0xFFFF7FFF
_080284C0: .4byte 0x00000000
_080284C4: .4byte 0x00800000
.syntax divided
