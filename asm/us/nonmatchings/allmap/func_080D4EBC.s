.syntax unified
	.align 2, 0
	.global func_080D4EBC
	.thumb
	.thumb_func
	.type func_080D4EBC, %function
func_080D4EBC: @ 080D4EBC
	push {r4, r5, r6, lr}
	add sp, #-0x004
	ldr r4, _080D50E4 @ =0x0203C4B4
	movs r0, #0xC4
	bl func_08000918
	str r0, [r4, #0x00]
	adds r0, #0xC0
	movs r1, #0xFF
	strb r1, [r0, #0x00]
	ldr r0, [r4, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xBC
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [r2, #0x00]
	ldr r2, _080D50E8 @ =0x0203C538
	ldr r1, _080D50EC @ =0x0203C590
	ldrb r1, [r1, #0x06]
	strb r1, [r2, #0x00]
	movs r1, #0x23
	bl func_08000E64
	ldr r0, [r4, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x9C
	movs r2, #0x00
	str r2, [r1, #0x00]
	adds r0, #0x98
	str r2, [r0, #0x00]
	movs r3, #0x00
_080D4EFA:
	ldr r0, [r4, #0x00]
	lsls r1, r2, #0x02
	adds r0, #0x14
	adds r0, r0, r1
	str r3, [r0, #0x00]
	adds r2, #0x01
	cmp r2, #0x1F
	ble _080D4EFA
	ldr r6, _080D50E4 @ =0x0203C4B4
	ldr r2, [r6, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xB6
	movs r4, #0x00
	movs r1, #0x20
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strh r1, [r0, #0x00]
	adds r0, #0x06
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strh r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x20
	bl func_080D576C
	ldr r3, [r6, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA0
	strh r4, [r0, #0x00]
	adds r0, #0x02
	strh r4, [r0, #0x00]
	adds r0, #0x12
	ldrh r0, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xB6
	ldrh r1, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xB8
	ldrh r2, [r2, #0x00]
	adds r3, #0xBA
	ldrh r3, [r3, #0x00]
	bl func_080D58AC
	ldr r2, [r6, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xA4
	movs r0, #0xA2
	adds r0, r0, r2
	mov r12, r0
	movs r3, #0x00
	ldsh r0, [r0, r3]
	adds r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	adds r1, #0x04
	mov r4, r12
	movs r5, #0x00
	ldsh r0, [r4, r5]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldr r1, _080D50F0 @ =0x0203C540
	adds r3, r2, #0x0
	adds r3, #0xAC
	adds r4, r2, #0x0
	adds r4, #0xA0
	ldrh r0, [r4, #0x00]
	ldrh r5, [r3, #0x00]
	adds r0, r0, r5
	strh r0, [r1, #0x00]
	ldr r1, _080D50F4 @ =0x0203C53C
	adds r5, r2, #0x0
	adds r5, #0xAE
	mov r2, r12
	ldrh r0, [r2, #0x00]
	ldrh r2, [r5, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldr r2, _080D50F8 @ =0x02034E8C
	movs r1, #0x00
	ldsh r0, [r3, r1]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r2, _080D50FC @ =0x02034E90
	movs r4, #0x00
	ldsh r0, [r5, r4]
	mov r5, r12
	movs r3, #0x00
	ldsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	movs r5, #0x00
_080D4FB8:
	ldr r0, [r6, #0x00]
	lsls r4, r5, #0x02
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D4FFA
	ldr r0, [r6, #0x00]
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x04]
	adds r0, r2, #0x0
	adds r0, #0x8C
	movs r1, #0x00
	ldsh r4, [r0, r1]
	adds r0, #0x02
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, #0x0C
	ldrh r2, [r0, #0x00]
	movs r3, #0x00
	ldr r0, _080D50E8 @ =0x0203C538
	ldrb r0, [r0, #0x00]
	cmp r5, r0
	bne _080D4FF4
	movs r3, #0x01
_080D4FF4:
	adds r0, r4, #0x0
	bl func_080D4D50
_080D4FFA:
	adds r5, #0x01
	cmp r5, #0x1F
	ble _080D4FB8
	ldr r5, _080D50E4 @ =0x0203C4B4
	ldr r3, [r5, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xA0
	adds r0, r3, #0x0
	adds r0, #0xAC
	movs r4, #0x00
	ldsh r2, [r0, r4]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D5018
	adds r0, r2, #0x7
_080D5018:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r1, [r1, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r3, #0x0
	adds r4, #0xA2
	adds r0, r3, #0x0
	adds r0, #0xAE
	movs r3, #0x00
	ldsh r2, [r0, r3]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D503A
	adds r0, r2, #0x7
_080D503A:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r2, [r4, #0x00]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_080051C4
	ldr r3, [r5, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xA0
	adds r0, r3, #0x0
	adds r0, #0xAC
	movs r4, #0x00
	ldsh r2, [r0, r4]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D5064
	adds r0, r2, #0x7
_080D5064:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r1, [r1, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r3, #0x0
	adds r4, #0xA2
	adds r0, r3, #0x0
	adds r0, #0xAE
	movs r3, #0x00
	ldsh r2, [r0, r3]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D5086
	adds r0, r2, #0x7
_080D5086:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r2, [r4, #0x00]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_080051C4
	ldr r0, [r5, #0x00]
	ldr r1, _080D50E8 @ =0x0203C538
	ldrb r2, [r1, #0x00]
	lsls r2, r2, #0x02
	adds r1, r0, #0x0
	adds r1, #0x14
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x04]
	adds r1, r2, #0x0
	adds r1, #0x8C
	ldrh r4, [r1, #0x00]
	ldr r3, _080D5100 @ =0xFFFF0000
	ldr r1, [sp, #0x000]
	ands r1, r3
	orrs r1, r4
	str r1, [sp, #0x000]
	adds r2, #0x8E
	ldrh r2, [r2, #0x00]
	lsls r2, r2, #0x10
	ldr r3, _080D5104 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp, #0x000]
	ldr r1, _080D5108 @ =0x09EF4DD8
	mov r2, sp
	bl func_08000E14
	ldr r1, [r5, #0x00]
	adds r1, #0x94
	str r0, [r1, #0x00]
	bl func_080D53F8
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D50E4: .4byte 0x0203C4B4
_080D50E8: .4byte 0x0203C538
_080D50EC: .4byte 0x0203C590
_080D50F0: .4byte 0x0203C540
_080D50F4: .4byte 0x0203C53C
_080D50F8: .4byte 0x02034E8C
_080D50FC: .4byte 0x02034E90
_080D5100: .4byte 0xFFFF0000
_080D5104: .4byte 0x0000FFFF
_080D5108: .4byte 0x09EF4DD8
.syntax divided
