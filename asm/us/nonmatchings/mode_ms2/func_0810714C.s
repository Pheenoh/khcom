.syntax unified
	.align 2, 0
	.global func_0810714C
	.thumb
	.thumb_func
	.type func_0810714C, %function
func_0810714C: @ 0810714C
	push {lr}
	ldr r0, _0810717C @ =0x02035E2E
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_0810712C
	ldr r1, _08107180 @ =0x02035E9C
	movs r3, #0x00
	ldsh r2, [r1, r3]
	ldr r1, _08107184 @ =0x02035E9A
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r2, r1
	lsls r1, r2, #0x01
	adds r1, r1, r2
	ldr r2, _08107188 @ =0x02035E98
	adds r0, r0, r1
	ldrh r2, [r2, #0x00]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0810717C: .4byte 0x02035E2E
_08107180: .4byte 0x02035E9C
_08107184: .4byte 0x02035E9A
_08107188: .4byte 0x02035E98
.syntax divided
