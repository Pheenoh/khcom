.syntax unified
	.align 2, 0
	.global func_0810C57C
	.thumb
	.thumb_func
	.type func_0810C57C, %function
func_0810C57C: @ 0810C57C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x10
	movs r2, #0x12
	ldsh r0, [r5, r2]
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r0, r1
	beq _0810C628
	strh r2, [r5, #0x12]
	ldrh r1, [r5, #0x1E]
	ldrh r2, [r5, #0x20]
	adds r0, r5, #0x0
	movs r3, #0x01
	bl func_0810C494
	movs r2, #0x01
	movs r1, #0x12
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	ble _0810C5B2
	ldrb r1, [r5, #0x1C]
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r2, r0, #0x1F
	b _0810C5BA
_0810C5B2:
	ldrb r0, [r5, #0x1C]
	cmp r0, #0x00
	bne _0810C5BA
	movs r2, #0x00
_0810C5BA:
	cmp r2, #0x01
	bne _0810C5F4
	movs r2, #0x8C
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	str r0, [r4, #0x00]
	str r1, [r4, #0x04]
	movs r0, #0x90
	lsls r0, r0, #0x02
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	orrs r0, r2
	str r0, [r4, #0x00]
	str r1, [r4, #0x04]
	movs r1, #0xE0
	lsls r1, r1, #0x02
	adds r4, r5, r1
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	orrs r0, r2
	str r0, [r4, #0x00]
	str r1, [r4, #0x04]
	b _0810C628
_0810C5F4:
	movs r2, #0x8C
	lsls r2, r2, #0x01
	adds r3, r5, r2
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
	str r0, [r3, #0x00]
	str r1, [r3, #0x04]
	movs r0, #0x90
	lsls r0, r0, #0x02
	adds r3, r5, r0
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	ands r0, r2
	str r0, [r3, #0x00]
	str r1, [r3, #0x04]
	movs r1, #0xE0
	lsls r1, r1, #0x02
	adds r3, r5, r1
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	ands r0, r2
	str r0, [r3, #0x00]
	str r1, [r3, #0x04]
_0810C628:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
