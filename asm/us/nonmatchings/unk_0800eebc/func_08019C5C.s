.syntax unified
	.align 2, 0
	.global func_08019C5C
	.thumb
	.thumb_func
	.type func_08019C5C, %function
func_08019C5C: @ 08019C5C
	push {r4, r5, r6, r7, lr}
	ldr r7, _08019CAC @ =0x02039B84
	ldr r6, [r7, #0x00]
	adds r1, r6, #0x0
	adds r1, #0xA0
	movs r0, #0x01
	str r0, [r1, #0x00]
	ldr r4, [r6, #0x68]
	ldr r5, [r6, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x10
	adds r0, r4, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08019C8C
	movs r2, #0x20
	movs r3, #0x00
	adds r0, r4, #0x0
	orrs r0, r2
	adds r1, r5, #0x0
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
_08019C8C:
	ldr r5, [r7, #0x00]
	ldr r2, [r5, #0x68]
	ldr r3, [r5, #0x6C]
	movs r0, #0x41
	negs r0, r0
	ands r2, r0
	ldr r4, _08019CB0 @ =0xDFFFFFFF
	adds r0, r2, #0x0
	ands r0, r4
	adds r1, r3, #0x0
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08019CAC: .4byte 0x02039B84
_08019CB0: .4byte 0xDFFFFFFF
.syntax divided
