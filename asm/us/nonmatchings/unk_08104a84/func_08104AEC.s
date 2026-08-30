.syntax unified
	.align 2, 0
	.global func_08104AEC
	.thumb
	.thumb_func
	.type func_08104AEC, %function
func_08104AEC: @ 08104AEC
	push {lr}
	ldr r0, _08104B1C @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08104A84
	ldr r1, _08104B20 @ =0x02035CE4
	movs r3, #0x00
	ldsh r2, [r1, r3]
	ldr r1, _08104B24 @ =0x02035CE2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r2, r1
	lsls r1, r2, #0x01
	adds r1, r1, r2
	ldr r2, _08104B28 @ =0x02035CE0
	adds r0, r0, r1
	ldrh r2, [r2, #0x00]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08104B1C: .4byte 0x02035C18
_08104B20: .4byte 0x02035CE4
_08104B24: .4byte 0x02035CE2
_08104B28: .4byte 0x02035CE0
.syntax divided
