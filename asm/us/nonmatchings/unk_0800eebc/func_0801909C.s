.syntax unified
	.align 2, 0
	.global func_0801909C
	.thumb
	.thumb_func
	.type func_0801909C, %function
func_0801909C: @ 0801909C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov r9, r1
	adds r5, r3, #0x0
	ldr r7, [sp, #0x01C]
	ldr r1, _080190DC @ =0x02039B84
	ldr r4, [r1, #0x00]
	ldr r3, [r4, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r12, r1
	cmp r3, r0
	bne _080190E0
	asrs r1, r2, #0x08
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r5, #0x08
	asrs r0, r7, #0x08
	adds r1, r1, r0
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	b _08019104
	.byte 0x00, 0x00
_080190DC: .4byte 0x02039B84
_080190E0:
	asrs r1, r2, #0x08
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	adds r0, r1, #0x0
	muls r0, r3
	lsls r0, r0, #0x08
	lsrs r6, r0, #0x10
	asrs r1, r5, #0x08
	asrs r0, r7, #0x08
	adds r1, r1, r0
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	adds r0, r1, #0x0
	muls r0, r3
	lsls r0, r0, #0x08
	lsrs r7, r0, #0x10
_08019104:
	mov r1, r12
	ldr r0, [r1, #0x00]
	ldrb r0, [r0, #0x18]
	cmp r0, #0x00
	bne _08019124
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x78
	mov r2, r8
	strh r0, [r2, #0x00]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x50
	mov r3, r9
	strh r0, [r3, #0x00]
	b _08019180
_08019124:
	negs r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _0801918C @ =0x08121400
	mov r12, r0
	adds r5, r2, #0x0
	adds r5, #0x40
	movs r0, #0xFF
	adds r1, r5, #0x0
	ands r1, r0
	lsls r0, r1, #0x01
	add r0, r12
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	adds r4, r0, #0x0
	muls r4, r3
	adds r1, #0x40
	lsls r1, r1, #0x01
	add r1, r12
	movs r6, #0x00
	ldsh r0, [r1, r6]
	muls r3, r0
	lsls r2, r2, #0x01
	add r2, r12
	movs r1, #0x00
	ldsh r0, [r2, r1]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	muls r0, r1
	adds r4, r4, r0
	lsls r5, r5, #0x01
	add r5, r12
	movs r2, #0x00
	ldsh r0, [r5, r2]
	muls r0, r1
	adds r3, r3, r0
	asrs r4, r4, #0x08
	adds r4, #0x78
	mov r6, r8
	strh r4, [r6, #0x00]
	asrs r3, r3, #0x08
	adds r3, #0x50
	mov r0, r9
	strh r3, [r0, #0x00]
_08019180:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801918C: .4byte 0x08121400
.syntax divided
