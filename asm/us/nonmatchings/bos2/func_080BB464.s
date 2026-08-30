.syntax unified
	.align 2, 0
	.global func_080BB464
	.thumb
	.thumb_func
	.type func_080BB464, %function
func_080BB464: @ 080BB464
	push {r4, r5, r6, lr}
	adds r2, r0, #0x0
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r3, r2, r0
	movs r1, #0xFC
	lsls r1, r1, #0x01
	adds r4, r2, r1
	ldr r5, _080BB4BC @ =0x08121400
	ldrb r0, [r3, #0x08]
	lsls r0, r0, #0x01
	adds r0, r0, r5
	movs r6, #0x00
	ldsh r1, [r0, r6]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldr r1, [r3, #0x00]
	adds r1, r1, r0
	ldr r2, [r2, #0x0C]
	ldr r0, [r2, #0x00]
	adds r1, r1, r0
	str r1, [r4, #0x00]
	ldrb r0, [r3, #0x08]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r5
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x02
	ldr r0, [r3, #0x04]
	adds r0, r0, r1
	ldr r1, [r2, #0x08]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	ldr r0, [r2, #0x04]
	str r0, [r4, #0x04]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BB4BC: .4byte 0x08121400
.syntax divided
