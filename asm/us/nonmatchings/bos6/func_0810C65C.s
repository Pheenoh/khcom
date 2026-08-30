.syntax unified
	.align 2, 0
	.global func_0810C65C
	.thumb
	.thumb_func
	.type func_0810C65C, %function
func_0810C65C: @ 0810C65C
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r5, r1, #0x0
	movs r6, #0x00
	movs r2, #0x06
	ldsh r0, [r4, r2]
	cmp r0, #0x01
	bne _0810C688
	movs r3, #0xFF
	lsls r3, r3, #0x01
	adds r0, r4, r3
	movs r1, #0x02
	strh r1, [r0, #0x00]
	ldr r2, _0810C684 @ =0x0000033E
	adds r0, r4, r2
	strh r1, [r0, #0x00]
	b _0810C74C
	.byte 0x00, 0x00
_0810C684: .4byte 0x0000033E
_0810C688:
	cmp r1, #0x00
	bne _0810C6E8
	movs r2, #0x00
	movs r3, #0xFA
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0810C6A6
	movs r0, #0xFF
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x02
	strh r0, [r1, #0x00]
	b _0810C6AE
_0810C6A6:
	movs r1, #0xFF
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strh r6, [r0, #0x00]
_0810C6AE:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r0, r4, r0
	movs r2, #0xFB
	lsls r2, r2, #0x01
	adds r1, r0, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r2, #0x01
	movs r3, #0xCD
	lsls r3, r3, #0x02
	adds r0, r4, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0810C6DC
	ldr r0, _0810C6D8 @ =0x0000033E
	adds r1, r4, r0
	b _0810C726
_0810C6D8: .4byte 0x0000033E
_0810C6DC:
	ldr r3, _0810C6E4 @ =0x0000033E
	adds r1, r4, r3
	movs r0, #0x00
	b _0810C728
_0810C6E4: .4byte 0x0000033E
_0810C6E8:
	adds r0, r4, #0x0
	bl func_0810C630
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x06
	adds r1, r4, r1
	movs r2, #0xFF
	lsls r2, r2, #0x01
	adds r1, r1, r2
	strh r5, [r1, #0x00]
	movs r1, #0x01
	eors r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x06
	adds r1, r4, r1
	movs r3, #0xFA
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0810C72C
	movs r0, #0xFF
	lsls r0, r0, #0x01
	adds r1, r1, r0
_0810C726:
	movs r0, #0x02
_0810C728:
	strh r0, [r1, #0x00]
	b _0810C734
_0810C72C:
	movs r3, #0xFF
	lsls r3, r3, #0x01
	adds r0, r1, r3
	strh r6, [r0, #0x00]
_0810C734:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x06
	adds r1, r4, r1
	movs r0, #0xFB
	lsls r0, r0, #0x01
	adds r1, r1, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r6, #0x01
_0810C74C:
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
