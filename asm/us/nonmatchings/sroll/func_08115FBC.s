.syntax unified
	.align 2, 0
	.global func_08115FBC
	.thumb
	.thumb_func
	.type func_08115FBC, %function
func_08115FBC: @ 08115FBC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	movs r7, #0x00
	b _08115FF8
_08115FC6:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _08115FDA
	ldrb r0, [r5, #0x00]
	lsls r0, r0, #0x08
	ldrb r4, [r5, #0x01]
	orrs r4, r0
	adds r5, #0x02
	b _08115FE6
_08115FDA:
	ldrb r0, [r5, #0x00]
	bl func_08116CDC
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, #0x01
_08115FE6:
	ldr r1, [r6, #0x34]
	ldr r2, [r6, #0x3C]
	ldr r3, [r6, #0x40]
	adds r0, r4, #0x0
	bl func_08115F8C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r7, r0
_08115FF8:
	ldrb r1, [r5, #0x00]
	cmp r1, #0x00
	bne _08115FC6
	adds r0, r7, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
