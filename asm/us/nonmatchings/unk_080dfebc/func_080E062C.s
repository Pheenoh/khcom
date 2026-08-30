.syntax unified
	.align 2, 0
	.global func_080E062C
	.thumb
	.thumb_func
	.type func_080E062C, %function
func_080E062C: @ 080E062C
	push {r4, r5, r6, lr}
	ldr r5, _080E065C @ =0x0203C590
	ldrb r0, [r5, #0x07]
	cmp r0, #0x03
	bhi _080E0724
	bl func_080DFB7C
	ldrh r1, [r0, #0x02]
	lsls r1, r1, #0x05
	adds r4, r1, #0x0
	adds r4, #0x10
	ldrh r0, [r0, #0x04]
	lsls r0, r0, #0x04
	adds r6, r0, #0x0
	adds r6, #0x0A
	ldrb r0, [r5, #0x07]
	cmp r0, #0x01
	beq _080E0698
	cmp r0, #0x01
	bgt _080E0660
	cmp r0, #0x00
	beq _080E066A
	b _080E073A
	.byte 0x00, 0x00
_080E065C: .4byte 0x0203C590
_080E0660:
	cmp r0, #0x02
	beq _080E06C8
	cmp r0, #0x03
	beq _080E06F8
	b _080E073A
_080E066A:
	ldr r0, _080E0690 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xDC
	lsls r0, r4, #0x08
	ldr r3, _080E0694 @ =0xFFFFF400
	adds r0, r0, r3
	str r0, [r1, #0x00]
	adds r1, #0x04
	lsls r0, r6, #0x08
	movs r3, #0x80
	lsls r3, r3, #0x04
	adds r0, r0, r3
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0xAD
	strb r0, [r1, #0x00]
	b _080E073A
	.byte 0x00, 0x00
_080E0690: .4byte 0x02039BA0
_080E0694: .4byte 0xFFFFF400
_080E0698:
	ldr r0, _080E06C0 @ =0x02039BA0
	ldr r3, [r0, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xDC
	lsls r0, r4, #0x08
	movs r1, #0xC0
	lsls r1, r1, #0x04
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xE0
	lsls r0, r6, #0x08
	ldr r2, _080E06C4 @ =0xFFFFF800
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x2D
	strb r0, [r1, #0x00]
	b _080E073A
	.byte 0x00, 0x00
_080E06C0: .4byte 0x02039BA0
_080E06C4: .4byte 0xFFFFF800
_080E06C8:
	ldr r0, _080E06EC @ =0x02039BA0
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xDC
	lsls r0, r4, #0x08
	ldr r3, _080E06F0 @ =0xFFFFF400
	adds r0, r0, r3
	str r0, [r1, #0x00]
	adds r1, #0x04
	lsls r0, r6, #0x08
	ldr r3, _080E06F4 @ =0xFFFFF800
	adds r0, r0, r3
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0xD3
	strb r0, [r1, #0x00]
	b _080E073A
	.byte 0x00, 0x00
_080E06EC: .4byte 0x02039BA0
_080E06F0: .4byte 0xFFFFF400
_080E06F4: .4byte 0xFFFFF800
_080E06F8:
	ldr r0, _080E0720 @ =0x02039BA0
	ldr r3, [r0, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xDC
	lsls r0, r4, #0x08
	movs r1, #0xC0
	lsls r1, r1, #0x04
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xE0
	lsls r0, r6, #0x08
	movs r2, #0x80
	lsls r2, r2, #0x04
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x53
	strb r0, [r1, #0x00]
	b _080E073A
_080E0720: .4byte 0x02039BA0
_080E0724:
	ldr r4, _080E0758 @ =0x02039BA0
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xDC
	adds r1, #0xE0
	bl func_080E524C
	ldr r0, [r4, #0x00]
	adds r0, #0xE4
	movs r1, #0x80
	strb r1, [r0, #0x00]
_080E073A:
	ldr r0, _080E075C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080E0764
	ldr r0, _080E0758 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x8C
	ldr r1, _080E0760 @ =0x09EDAF78
	movs r2, #0x00
	bl func_08000E14
	b _080E0772
	.byte 0x00, 0x00
_080E0758: .4byte 0x02039BA0
_080E075C: .4byte 0x02039BB0
_080E0760: .4byte 0x09EDAF78
_080E0764:
	ldr r0, _080E0778 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x8C
	ldr r1, _080E077C @ =0x09EDAF60
	movs r2, #0x00
	bl func_08000E14
_080E0772:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080E0778: .4byte 0x02039BA0
_080E077C: .4byte 0x09EDAF60
.syntax divided
