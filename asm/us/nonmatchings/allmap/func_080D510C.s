.syntax unified
	.align 2, 0
	.global func_080D510C
	.thumb
	.thumb_func
	.type func_080D510C, %function
func_080D510C: @ 080D510C
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0x0
	adds r0, #0xAC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r2, #0x0
	adds r1, #0xA0
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r0, r0, r1
	lsls r7, r0, #0x08
	adds r0, r2, #0x0
	adds r0, #0xAE
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r2, #0x0
	adds r1, #0xA2
	movs r2, #0x00
	ldsh r1, [r1, r2]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	mov r12, r0
	ldr r2, _080D515C @ =0x02034E8C
	ldr r0, [r2, #0x00]
	subs r0, r7, r0
	asrs r4, r0, #0x03
	ldr r1, _080D5160 @ =0x02034E90
	ldr r0, [r1, #0x00]
	mov r3, r12
	subs r0, r3, r0
	asrs r0, r0, #0x03
	movs r3, #0x80
	lsls r3, r3, #0x04
	adds r6, r2, #0x0
	adds r5, r1, #0x0
	cmp r4, r3
	ble _080D5164
	adds r4, r3, #0x0
	b _080D516C
	.byte 0x00, 0x00
_080D515C: .4byte 0x02034E8C
_080D5160: .4byte 0x02034E90
_080D5164:
	ldr r1, _080D5194 @ =0xFFFFF800
	cmp r4, r1
	bge _080D516C
	adds r4, r1, #0x0
_080D516C:
	movs r1, #0x80
	lsls r1, r1, #0x04
	cmp r0, r1
	bgt _080D517A
	ldr r1, _080D5194 @ =0xFFFFF800
	cmp r0, r1
	bge _080D517C
_080D517A:
	adds r0, r1, #0x0
_080D517C:
	ldr r3, [r6, #0x00]
	ldr r2, [r5, #0x00]
	adds r1, r3, r4
	str r1, [r6, #0x00]
	adds r0, r2, r0
	str r0, [r5, #0x00]
	subs r0, r3, r1
	cmp r0, #0x00
	blt _080D5198
	cmp r0, #0x07
	ble _080D519E
	b _080D51A0
_080D5194: .4byte 0xFFFFF800
_080D5198:
	subs r0, r1, r3
	cmp r0, #0x07
	bgt _080D51A0
_080D519E:
	str r7, [r6, #0x00]
_080D51A0:
	ldr r0, [r5, #0x00]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080D51AE
	cmp r1, #0x07
	ble _080D51B4
	b _080D51B8
_080D51AE:
	subs r0, r0, r2
	cmp r0, #0x07
	bgt _080D51B8
_080D51B4:
	mov r0, r12
	str r0, [r5, #0x00]
_080D51B8:
	ldr r1, _080D51D0 @ =0x0203C540
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x08
	strh r0, [r1, #0x00]
	ldr r1, _080D51D4 @ =0x0203C53C
	ldr r0, [r5, #0x00]
	asrs r0, r0, #0x08
	strh r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D51D0: .4byte 0x0203C540
_080D51D4: .4byte 0x0203C53C
.syntax divided
