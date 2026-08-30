.syntax unified
	.align 2, 0
	.global func_081015E8
	.thumb
	.thumb_func
	.type func_081015E8, %function
func_081015E8: @ 081015E8
	push {r4, r5, lr}
	ldr r2, _08101638 @ =0x09993118
	ldr r0, _0810163C @ =0x0203588C
	ldr r1, _08101640 @ =0x02035884
	ldr r0, [r0, #0x00]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x08
	ldrh r2, [r2, #0x16]
	adds r0, r0, r2
	movs r5, #0x00
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	ldr r0, _08101644 @ =0x02035880
	ldr r0, [r0, #0x00]
	negs r0, r0
	asrs r1, r0, #0x08
	adds r0, r1, #0x0
	adds r0, #0x1C
	cmp r2, r0
	ble _08101618
	adds r0, #0x62
	cmp r2, r0
	blt _0810161A
_08101618:
	movs r5, #0x01
_0810161A:
	ldr r4, _08101648 @ =0x0203585C
	ldr r0, [r4, #0x00]
	bl func_08002C10
	ldr r0, _0810164C @ =0x09A3D77C
	cmp r5, #0x00
	bne _0810162A
	ldr r0, _08101650 @ =0x09617D58
_0810162A:
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_08101638: .4byte 0x09993118
_0810163C: .4byte 0x0203588C
_08101640: .4byte 0x02035884
_08101644: .4byte 0x02035880
_08101648: .4byte 0x0203585C
_0810164C: .4byte 0x09A3D77C
_08101650: .4byte 0x09617D58
.syntax divided
