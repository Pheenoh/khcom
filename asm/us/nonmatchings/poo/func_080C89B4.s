.syntax unified
	.align 2, 0
	.global func_080C89B4
	.thumb
	.thumb_func
	.type func_080C89B4, %function
func_080C89B4: @ 080C89B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	adds r0, #0x0C
	bl func_08005B34
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r4, #0x0
	adds r0, #0x78
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080C8A04
	adds r0, r4, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	muls r1, r5
	adds r1, r1, r2
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r3, r0, r6
	ldr r1, [r3, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C89F6
	negs r1, r1
_080C89F6:
	ldr r0, [r4, #0x28]
	adds r0, r0, r1
	str r0, [r4, #0x28]
	ldr r1, [r3, #0x04]
	ldr r0, [r4, #0x2C]
	adds r0, r0, r1
	str r0, [r4, #0x2C]
_080C8A04:
	adds r0, r4, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	muls r1, r5
	adds r1, r1, r2
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r6
	ldr r1, [r4, #0x30]
	ldr r0, [r0, #0x08]
	adds r1, r1, r0
	str r1, [r4, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x00, 0xB5, 0x03, 0x49, 0x0B, 0x22, 0xFF, 0xF7, 0xC1, 0xFF, 0x01, 0xBC, 0x00, 0x47
	.byte 0x00, 0x00, 0x5C, 0xC0, 0x6F, 0x09
.syntax divided
