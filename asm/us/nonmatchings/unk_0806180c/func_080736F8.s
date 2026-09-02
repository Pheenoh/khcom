.syntax unified
	.align 2, 0
	.global func_080736F8
	.thumb
	.thumb_func
	.type func_080736F8, %function
func_080736F8: @ 080736F8
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	adds r0, #0x27
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, [r3, #0x3C]
	adds r5, r1, r0
	ldr r6, _08073758 @ =0x02039DC8
	ldr r2, [r6, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x6C
	ldrh r0, [r0, #0x00]
	ldrh r1, [r5, #0x16]
	cmp r0, r1
	bcc _08073762
	adds r1, r3, #0x0
	adds r1, #0x2A
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08073762
	ldr r0, [r2, #0x64]
	movs r4, #0x01
	orrs r0, r4
	str r0, [r2, #0x64]
	strb r4, [r1, #0x00]
	movs r0, #0x08
	strb r0, [r3, #0x1E]
	ldrh r1, [r5, #0x14]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _0807375C
	adds r0, r2, #0x0
	adds r0, #0x7C
	strb r4, [r0, #0x00]
	ldr r0, [r6, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, #0x88
	strb r1, [r0, #0x00]
	ldr r0, [r6, #0x00]
	adds r0, #0x89
	movs r1, #0x20
	b _08073760
	.byte 0x00, 0x00
_08073758: .4byte 0x02039DC8
_0807375C:
	adds r0, r2, #0x0
	adds r0, #0x7C
_08073760:
	strb r1, [r0, #0x00]
_08073762:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
