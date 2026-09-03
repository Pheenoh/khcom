.syntax unified
	.align 2, 0
	.global func_080F4EE4
	.thumb
	.thumb_func
	.type func_080F4EE4, %function
func_080F4EE4: @ 080F4EE4
	push {r4, r5, lr}
	mov r12, r0
	ldr r4, _080F4F5C @ =0x08121400
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	adds r0, #0x80
	movs r3, #0xFF
	ands r0, r3
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	mov r2, r12
	adds r2, #0xCC
	movs r5, #0x00
	ldsh r1, [r2, r5]
	muls r0, r1
	asrs r0, r0, #0x08
	mov r5, r12
	adds r5, #0xB4
	strh r0, [r5, #0x00]
	mov r0, r12
	adds r0, #0xCF
	ldrb r0, [r0, #0x00]
	adds r0, #0x80
	ands r0, r3
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	movs r3, #0x00
	ldsh r1, [r2, r3]
	muls r0, r1
	asrs r0, r0, #0x08
	subs r2, #0x16
	strh r0, [r2, #0x00]
	ldrh r0, [r5, #0x00]
	adds r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _080F4F44
	movs r0, #0x02
	strh r0, [r5, #0x00]
_080F4F44:
	ldrh r0, [r2, #0x00]
	adds r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _080F4F54
	movs r0, #0x02
	strh r0, [r2, #0x00]
_080F4F54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080F4F5C: .4byte 0x08121400
.syntax divided
