.syntax unified
	.align 2, 0
	.global func_08116AD8
	.thumb
	.thumb_func
	.type func_08116AD8, %function
func_08116AD8: @ 08116AD8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	b _08116AE8
_08116AE2:
	adds r0, r4, #0x0
	bl sub_0811683C
_08116AE8:
	adds r0, r4, #0x0
	bl func_081161DC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08116AE2
	cmp r5, #0x01
	bne _08116B08
	ldrh r1, [r4, #0x00]
	adds r0, r5, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08116B08
	adds r0, r4, #0x0
	bl func_08116B1C
_08116B08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
