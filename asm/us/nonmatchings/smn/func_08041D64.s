.syntax unified
	.align 2, 0
	.global func_08041D64
	.thumb
	.thumb_func
	.type func_08041D64, %function
func_08041D64: @ 08041D64
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	movs r0, #0xB8
	lsls r0, r0, #0x01
	adds r6, r7, r0
	ldr r2, _08041DD8 @ =0x08121400
	movs r1, #0xAC
	lsls r1, r1, #0x01
	adds r5, r7, r1
	ldrb r0, [r5, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x04
	ldr r0, [r7, #0x3C]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	movs r0, #0xBA
	lsls r0, r0, #0x01
	adds r3, r7, r0
	ldrb r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, [r7, #0x40]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	bl GetRandom
	ldrb r4, [r5, #0x00]
	adds r4, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x21
	bl __umodsi3
	adds r0, r0, r4
	strb r0, [r5, #0x00]
	ldr r0, [r6, #0x00]
	ldr r1, [r7, #0x3C]
	subs r0, r0, r1
	cmp r0, #0x00
	ble _08041DDC
	ldr r0, [r7, #0x6C]
	ldr r1, [r7, #0x70]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	b _08041DE6
_08041DD8: .4byte 0x08121400
_08041DDC:
	ldr r0, [r7, #0x6C]
	ldr r1, [r7, #0x70]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
_08041DE6:
	str r0, [r7, #0x6C]
	str r1, [r7, #0x70]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
