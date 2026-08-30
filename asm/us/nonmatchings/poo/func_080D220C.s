.syntax unified
	.align 2, 0
	.global func_080D220C
	.thumb
	.thumb_func
	.type func_080D220C, %function
func_080D220C: @ 080D220C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	mov r8, r1
	ldr r2, [r4, #0x20]
	asrs r2, r2, #0x08
	ldr r0, _080D225C @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r4, #0x24]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x28]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080D2260 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r7, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x0C
	adds r2, r2, r0
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r2, r0
	bhi _080D2258
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	movs r0, #0x08
	negs r0, r0
	cmp r5, r0
	blt _080D2258
	cmp r5, #0xA8
	ble _080D2264
_080D2258:
	movs r0, #0x00
	b _080D22A4
_080D225C: .4byte 0x0203C40C
_080D2260: .4byte 0x0203C3F8
_080D2264:
	adds r0, r4, #0x0
	adds r0, #0x50
	ldrb r0, [r0, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x04
	cmp r0, #0x00
	beq _080D2274
	adds r6, #0x01
_080D2274:
	adds r0, r4, #0x0
	bl func_080D2034
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x00]
	mov r0, r8
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r1, [r4, #0x24]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080D22B0 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl func_080023E0
	movs r0, #0x01
_080D22A4:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080D22B0: .4byte 0xFFFFEFFC
.syntax divided
