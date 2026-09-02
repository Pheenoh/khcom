.syntax unified
	.align 2, 0
	.global func_08099928
	.thumb
	.thumb_func
	.type func_08099928, %function
func_08099928: @ 08099928
	push {r4, r5, lr}
	mov r12, r0
	ldr r3, _080999A0 @ =0x08121400
	adds r0, #0xE9
	ldrb r0, [r0, #0x00]
	adds r0, #0x80
	movs r2, #0xFF
	ands r0, r2
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	mov r5, r12
	adds r5, #0xE2
	movs r4, #0x00
	ldsh r1, [r5, r4]
	muls r0, r1
	asrs r0, r0, #0x08
	mov r4, r12
	adds r4, #0xD0
	strh r0, [r4, #0x00]
	mov r0, r12
	adds r0, #0xE8
	ldrb r0, [r0, #0x00]
	adds r0, #0x80
	ands r0, r2
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	movs r2, #0x00
	ldsh r1, [r5, r2]
	muls r0, r1
	asrs r0, r0, #0x08
	mov r1, r12
	adds r1, #0xD2
	strh r0, [r1, #0x00]
	ldrh r0, [r4, #0x00]
	adds r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _0809998A
	movs r0, #0x02
	strh r0, [r4, #0x00]
_0809998A:
	ldrh r0, [r1, #0x00]
	adds r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _0809999A
	movs r0, #0x02
	strh r0, [r1, #0x00]
_0809999A:
	pop {r4, r5}
	pop {r0}
	bx r0
_080999A0: .4byte 0x08121400
.syntax divided
