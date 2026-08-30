.syntax unified
	.align 2, 0
	.global mode_worldwarp_2
	.thumb
	.thumb_func
	.type mode_worldwarp_2, %function
mode_worldwarp_2: @ 08101474
	push {r4, r5, r6, lr}
	ldr r0, _081014EC @ =0x02035514
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _081014F0 @ =0x02035510
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081014F4 @ =0x0203551C
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _081014F8 @ =0x02035518
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081014FC @ =0x02035554
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _08101500 @ =0x02035550
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r5, #0x00
	ldr r6, _08101504 @ =0x020355A8
_081014AA:
	lsls r4, r5, #0x02
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	beq _081014B6
	bl func_08002C10
_081014B6:
	ldr r0, _08101508 @ =0x02035570
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081014C4
	bl func_080028C0
_081014C4:
	adds r6, #0x04
	adds r5, #0x01
	cmp r5, #0x0C
	ble _081014AA
	ldr r0, _0810150C @ =0x02035618
	movs r1, #0x18
	bl func_08065AE0
	ldr r0, _08101510 @ =0x020356E0
	movs r1, #0x18
	bl func_08065AE0
	ldr r0, _08101514 @ =0x0203550C
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081014EC: .4byte 0x02035514
_081014F0: .4byte 0x02035510
_081014F4: .4byte 0x0203551C
_081014F8: .4byte 0x02035518
_081014FC: .4byte 0x02035554
_08101500: .4byte 0x02035550
_08101504: .4byte 0x020355A8
_08101508: .4byte 0x02035570
_0810150C: .4byte 0x02035618
_08101510: .4byte 0x020356E0
_08101514: .4byte 0x0203550C
.syntax divided
