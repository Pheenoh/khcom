.syntax unified
	.align 2, 0
	.global func_08019190
	.thumb
	.thumb_func
	.type func_08019190, %function
func_08019190: @ 08019190
	push {r4, lr}
	add sp, #-0x020
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x09
	beq _080191C2
	adds r0, #0xD8
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080191B0
	movs r4, #0x82
	lsls r4, r4, #0x01
	adds r1, r0, r4
	b _080191B6
_080191B0:
	movs r0, #0x82
	lsls r0, r0, #0x01
	adds r1, r2, r0
_080191B6:
	movs r4, #0x00
	ldsh r0, [r1, r4]
	cmp r0, #0x00
	bgt _0801925E
	movs r0, #0x32
	strh r0, [r1, #0x00]
_080191C2:
	ldr r0, [r2, #0x04]
	str r0, [sp, #0x000]
	ldr r0, [r2, #0x08]
	str r0, [sp, #0x004]
	adds r0, r2, #0x0
	adds r0, #0x9C
	ldrh r1, [r0, #0x00]
	lsrs r1, r1, #0x01
	lsls r1, r1, #0x08
	ldr r0, [r2, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x008]
	ldr r0, _0801920C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0801921E
	cmp r3, #0x09
	bne _08019218
	mov r2, sp
	ldr r0, _08019210 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0xE5
	lsls r3, r3, #0x01
	adds r1, r0, r3
	ldrb r1, [r1, #0x00]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0x00
	bge _08019202
	negs r1, r1
_08019202:
	strh r1, [r2, #0x12]
	adds r0, #0x2C
	ldr r1, _08019214 @ =0x09EDE458
	b _08019240
	.byte 0x00, 0x00
_0801920C: .4byte 0x02039BB0
_08019210: .4byte 0x02039B84
_08019214: .4byte 0x09EDE458
_08019218:
	mov r0, sp
	strh r3, [r0, #0x12]
	b _08019238
_0801921E:
	mov r0, sp
	strh r3, [r0, #0x12]
	cmp r3, #0x09
	bne _08019250
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x06
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _0801925E
_08019238:
	ldr r0, _08019248 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _0801924C @ =0x09EDAEE8
_08019240:
	mov r2, sp
	bl func_08000E14
	b _0801925E
_08019248: .4byte 0x02039B84
_0801924C: .4byte 0x09EDAEE8
_08019250:
	ldr r0, _08019268 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _0801926C @ =0x09EDAEE8
	mov r2, sp
	bl func_08000E14
_0801925E:
	add sp, #0x020
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08019268: .4byte 0x02039B84
_0801926C: .4byte 0x09EDAEE8
.syntax divided
