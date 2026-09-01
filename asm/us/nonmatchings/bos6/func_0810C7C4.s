.syntax unified
	.align 2, 0
	.global func_0810C7C4
	.thumb
	.thumb_func
	.type func_0810C7C4, %function
func_0810C7C4: @ 0810C7C4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r2, _0810C7FC @ =0x09A4D154
	adds r3, r4, #0x0
	adds r3, #0x6A
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r1, #0x0F
	ands r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	str r0, [r4, #0x58]
	ldrh r0, [r3, #0x00]
	adds r0, #0x01
	strh r0, [r3, #0x00]
	ldrb r0, [r4, #0x00]
	cmp r0, #0x01
	bne _0810C7F6
	ldr r0, [r4, #0x58]
	ldr r1, _0810C800 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0810C7F6:
	pop {r4}
	pop {r0}
	bx r0
_0810C7FC: .4byte 0x09A4D154
_0810C800: .4byte 0xFFFFE800
.syntax divided
